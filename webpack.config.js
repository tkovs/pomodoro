const path = require("path");
const webpack = require("webpack");
const HtmlWebpackPlugin = require("html-webpack-plugin");
const outputDir = path.join(__dirname, "build/");

const isProd = process.env.NODE_ENV === "production";

module.exports = (env) => {
  const token = (() => {
    if (process.env.DSN_TOKEN != null) {
      return JSON.stringify(process.env.DSN_TOKEN);
    }

    if (env && env.DSN_TOKEN != null) {
      return JSON.stringify(env.DSN_TOKEN);
    }

    return undefined;
  })();

  return {
    entry: "./src/Index.bs.js",
    mode: isProd ? "production" : "development",
    output: {
      path: outputDir,
      filename: "Index.js",
    },
    plugins: [
      new HtmlWebpackPlugin({
        favicon: "./favicon.ico",
        template: "index.html",
        inject: false,
      }),
      new webpack.DefinePlugin({
        "process.env.DSN_TOKEN": token,
      }),
    ],
    devServer: {
      compress: true,
      contentBase: outputDir,
      port: process.env.PORT || 8000,
      historyApiFallback: true,
    },
    module: {
      rules: [
        {
          test: /\.(mp3)$/i,
          use: [
            {
              loader: "file-loader",
              options: {
                name: "[name].[ext]",
              },
            },
          ],
        },
      ],
    },
  };
};
