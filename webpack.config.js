const webpack = require('webpack')
const HtmlPlugin = require('webpack-html-plugin')
const join = require('path').join

const stats = {
  chunks: false,
  modules: false,
}

module.exports = [
  {
    entry: './src/index.re',
    output: {
      filename: 'bundle.js',
      path: join(__dirname, 'dist'),
      publicPath: '/',
    },
    module: {
      rules: [
        { test: /\.(re|ml)$/, use: 'bs-loader' },
      ],
    },
    resolve: {
      extensions: ['.re', '.ml', '.js']
    },
    plugins: [
      new HtmlPlugin({ template: './index.html' }),
      ...(process.env.NODE_ENV === 'production' ? [
        new webpack.optimize.UglifyJsPlugin({
          beautify: false,
          mangle: {
            screw_ie8: true,
            keep_fnames: true
          },
          compress: {
            screw_ie8: true
          },
          comments: false
        }),
        new webpack.DefinePlugin({
          'process.env.NODE_ENV': JSON.stringify('production')
        }),
      ] : [])
    ],
    stats,
    devServer: {
      stats,
    },
  },
]
