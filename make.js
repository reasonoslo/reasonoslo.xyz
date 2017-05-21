#!/bin/env node
const fs = require('fs')
const React = require('react')
const {renderToString} = require('react-dom/server')

const index = require('./lib/js/src/index')

console.log(index)

fs.writeFileSync('index.html',
  `<!DOCTYPE html>
  <html>
    <head>
      <title>Reason Oslo</title>
      <style>
        body { text-align: center; font-family: sans-serif; }
        body > div { margin-top: 10rem; }
        header { font-size: 2rem; }
        img { transition: all 0.5s ease-in; }
        img:hover { transform: rotate(5deg); }
      </style>
    </head>
    <body>${index.rendered}</body>
  </html>
`)
