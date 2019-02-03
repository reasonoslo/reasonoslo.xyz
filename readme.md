# reasonoslo.xyz

[![Netlify Status](https://api.netlify.com/api/v1/badges/c00ff0b4-f941-4bc7-b6d5-f8923aaa9671/deploy-status)](https://app.netlify.com/sites/trusting-wescoff-346d38/deploys)

Webpage for the Reason Oslo meetup.

## Setup for development

```shell
yarn

# Run this to start bucklescript compiler in watch mode
yarn build -w

# Run this to run webpack dev server
yarn dev:frontend

# Run this to run netlify functions
yarn dev:server
```

## Deployment

This site is deployed with [netlify][] and will automatically deploy master on
push.

[netlify]: https://www.netlify.com
