const express = require('express')
const next = require('next')

const dev = process.env.NODE_ENV !== 'production'
const app = next({ dev })
const handler = app.getRequestHandler()

app
  .prepare()
  .then(() => {
    const server = express()
    server.use('/static', express.static('./static'))

    server.get('*', (req, res) => {
      handler(req, res)
    })

    server.listen(3000)
  })
  .catch(error => {
    console.error(error)
    process.exit(1)
  })
