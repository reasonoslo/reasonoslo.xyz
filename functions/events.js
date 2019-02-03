const got = require("got");

const production = process.env.NODE_ENV === "production";

async function fetchEvents(status) {
  const response = await got(
    `http://api.meetup.com/2/events?group_urlname=Reason-Oslo&status=${status}`,
    { json: true }
  );
  return response.body.results || [];
}

async function fetch(argument) {
  switch (argument) {
    case "past":
    case "upcoming":
    case "suggested":
    case "proposed":
    case "draft":
    case "cancelled":
      return fetchEvents(argument);

    default:
      return [
        ...(await fetchEvents("past")),
        ...(await fetchEvents("upcoming"))
      ];
  }
}

export function response({ statusCode = 200, body = {} }) {
  return {
    statusCode,
    headers: {
      "content-type": "application/json"
    },
    body: JSON.stringify(body)
  };
}

export function handleError(cb) {
  return function _handleError(error) {};
}

exports.handler = async function(event) {
  try {
    console.log(event.httpMethod, event.path);
    const parts = (event.path || "").replace("/.netlify/functions").split("/");
    const argument = parts[2];

    console.log(argument);

    const events = await fetch(argument);
    return response({ body: { events } });
  } catch (error) {
    console.log(error);
    return response({
      statusCode: 500,
      body: {
        message: production ? "Internal server error" : error.toString()
      }
    });
  }
};
