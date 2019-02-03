module.exports = {
  target: 'node',
  node: {
    console: true,
    process: true,
    __dirname: true,
  },
  externals: {
    http: 'http',
  },
  module: {
    rules: [
      {
        test: /\.mjs$/,
        type: 'javascript/auto',
      },
    ],
  }
};
