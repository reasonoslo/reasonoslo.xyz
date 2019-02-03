module.exports = {
  target: 'node',
  node: false,
  externals: {},
  module: {
    rules: [
      {
        test: /\.mjs$/,
        type: 'javascript/auto',
      },
    ],
  },
};
