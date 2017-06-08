module.exports = {
  webpack: (config, { dev }) => {
    config.module.rules.push({ test: /\.(re|ml)$/, use: 'bs-loader' });
    return config
  }
}
