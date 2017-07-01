const express = require('express')
const next = require('next')

const dev = process.env.NODE_ENV !== 'production'
const app = next({ dev })
const handler = app.getRequestHandler()

async function main() {
  await app.prepare()

  const server = express()
  server.use('/static', express.static('./static'))

  server.get('*', (req, res) => {
    handler(req, res)
  })

  server.listen(process.env.PORT || 3000)
}

main()
  .catch(error => {
    console.error(error)
    process.exit(1)
  })
