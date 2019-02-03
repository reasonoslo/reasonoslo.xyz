const got = require("got");

async function fetchEvents(status) {
  const response = await got(
    `http://api.meetup.com/2/events?group_urlname=Reason-Oslo&status=${status}`,
    { json: true }
  );
  return response.body;
}

async function fetch(argument) {
  switch (argument) {
    case "upcoming":
    case "past":
      return fetchEvents(argument);
    default:
      return [
        ...(await fetchEvents("past")),
        ...(await fetchEvents("upcoming"))
      ];
  }
}

exports.handler = async function(event, context, callback) {
  try {
    const [_, name, argument] = (event.path || "").split("/");

    const events = await fetch(argument);
    callback(null, {
      statusCode: 200,
      headers: {
        "content-type": "application/json"
      },
      body: JSON.stringify({ events })
    });
  } catch (error) {
    callback(error);
  }
};
