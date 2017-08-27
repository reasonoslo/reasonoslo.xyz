const express = require('express')
const next = require('next')
const request = require('superagent')

const dev = process.env.NODE_ENV !== 'production'
const app = next({ dev })
const handler = app.getRequestHandler()

function fetchEvents(status) {
  return request.get(`http://api.meetup.com/2/events?group_urlname=Reason-Oslo&status=${status}`)
    .then(response => response.body)
    .then(response => response.results)
}

async function main() {
  await app.prepare()

  const server = express()
  server.use('/static', express.static('./static'))


  server.get('/api/events', (req, res, next) => {
    Promise.all([fetchEvents('past'), fetchEvents('upcoming')])
      .then(([past, upcoming]) => {
        res.send([...past, ...upcoming])
      })
      .catch(error => {
        next(error)
      })
    });

  server.get('/api/events/upcoming', (req, res, next) => {
    if (process.env.TEST_UPCOMING_EVENT) {
      return res.send([{id: '123', name: 'Hacktoghether #42', description: '🍕😎✌️🖥', time: new Date().getTime()}])
    }

    fetchEvents('upcoming')
      .then(events => {
        res.send(events)
      })
      .catch(error => {
        next(error)
      })
    });

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
