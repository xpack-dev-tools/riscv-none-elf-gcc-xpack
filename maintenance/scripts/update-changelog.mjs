/*
 * DO NOT EDIT! Automatically generated from template file:
 * npm-packages-helper/templates/common/maintenance/scripts/update-changelog-liquid.mjs
 *
 * This file is part of the xPack project (http://xpack.github.io).
 * Copyright (c) 2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

// ----------------------------------------------------------------------------

// Update CHANGELOG.md with the commits more recent than the most recent
// commit already listed in the file.
//
// Usage: node maintenance/scripts/update-changelog.mjs [--dry-run] [file]
//
// The file is expected to contain sections like:
//
//   ## 2024-10-30
//
//   * af09113 package.json update
//   * 4286082 logger.ts: update typedoc metadata
//
// in reverse chronological order.
//
// Raw lines in the 'git log' format ('2024-10-30 * af09113 subject'),
// placed before the first section header, are also converted.

import { execFileSync } from 'node:child_process'
import { readFileSync, writeFileSync } from 'node:fs'
import path from 'node:path'
import { fileURLToPath } from 'node:url'

const rootFolder = path.resolve(
  path.dirname(fileURLToPath(import.meta.url)),
  '..',
  '..'
)

const args = process.argv.slice(2)
const dryRun = args.includes('--dry-run')
const fileArgs = args.filter((arg) => !arg.startsWith('--'))
const changelogPath = path.resolve(rootFolder, fileArgs[0] ?? 'CHANGELOG.md')

// With --dry-run, stdout carries the file content, so the status
// messages go to stderr.
const report = dryRun ? console.error : console.log

const rawRegex = /^(\d{4}-\d{2}-\d{2}) \* (.*)$/
const commitRegex = /^(?:\d{4}-\d{2}-\d{2} )?\* ([0-9a-f]{7,40}) /

const lines = readFileSync(changelogPath, 'utf8').split('\n')

const firstHeader = lines.findIndex((line) => line.startsWith('## '))
if (firstHeader === -1) {
  console.error('No section header ("## ") found in the file.')
  process.exit(1)
}

// Split the text before the first header into the preamble and the
// raw lines (if any).
const preamble = []
const fileRawLines = []
for (const line of lines.slice(0, firstHeader)) {
  if (rawRegex.test(line)) {
    fileRawLines.push(line)
  } else if (fileRawLines.length === 0) {
    preamble.push(line)
  }
  // Blank lines between raw groups are dropped.
}
while (preamble.length > 0 && preamble[preamble.length - 1] === '') {
  preamble.pop()
}

const sections = lines.slice(firstHeader)

// Most recent commit: the first line with a commit id, either raw or
// in the final syntax.
let lastId
for (const line of [...fileRawLines, ...sections]) {
  const match = commitRegex.exec(line)
  if (match !== null) {
    lastId = match[1]
    break
  }
}
if (lastId === undefined) {
  console.error(`No commit id found in ${changelogPath}`)
  process.exit(1)
}

const gitOutput = execFileSync(
  'git',
  ['log', '--pretty=%cd * %h %s', '--date=short', `${lastId}..HEAD`],
  { cwd: rootFolder, encoding: 'utf8', maxBuffer: 64 * 1024 * 1024 }
)

const gitRawLines = gitOutput.split('\n').filter((line) => line !== '')

// Newest first: the git lines, then the raw lines already in the file.
const rawLines = [...gitRawLines, ...fileRawLines]

if (rawLines.length === 0) {
  report(`CHANGELOG is up to date (last commit ${lastId}).`)
  process.exit(0)
}

// Group consecutive lines with the same date.
/** @type {Array<{ date: string, items: string[] }>} */
const groups = []
for (const line of rawLines) {
  const match = rawRegex.exec(line)
  if (match === null) {
    continue
  }
  const [, date, rest] = match
  const last = groups.at(-1)
  if (last?.date === date) {
    last.items.push(`* ${rest}`)
  } else {
    groups.push({ date, items: [`* ${rest}`] })
  }
}

// If the oldest group has the same date as the first existing section,
// add its items to that section instead of duplicating the header.
let sectionsOut = sections
const oldest = groups[groups.length - 1]
if (sections[0] === `## ${oldest.date}`) {
  groups.pop()
  const rest = sections.slice(1)
  sectionsOut = [
    sections[0],
    '',
    ...oldest.items,
    ...(rest[0] === '' ? rest.slice(1) : rest),
  ]
}

const result = [...preamble, '']
for (const group of groups) {
  result.push(`## ${group.date}`, '', ...group.items, '')
}
result.push(...sectionsOut)

if (dryRun) {
  console.log(result.join('\n'))
} else {
  writeFileSync(changelogPath, result.join('\n'))
}
report(
  `${String(gitRawLines.length)} new commit(s) after ${lastId}, ` +
    `${String(fileRawLines.length)} raw line(s) converted.`
)

// ----------------------------------------------------------------------------
