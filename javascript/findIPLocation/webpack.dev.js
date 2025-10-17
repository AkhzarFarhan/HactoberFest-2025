const HtmlWebpackPlugin = require("html-webpack-plugin");
const path = require("path");

module.exports = {
    entry: "./src/app.js",
    mode: "production",
    output: {
        path: path.resolve(__dirname, "dist"),
        filename: "bundle.js"
    },
    module: {
        rules: [{
            test: /\.css$/,
            use: [{
                    loader: "style-loader"
                },
                {
                    loader: "css-loader"
                },
                {
                    loader: 'postcss-loader',
                    options: {
                        ident: 'postcss',
                        plugins: [
                            require('tailwindcss'),
                            require('autoprefixer'),
                        ],
                    },
                },
            ]
        }]
    },
    plugins: [
        new HtmlWebpackPlugin({
            template: "./src/views/index.html",
            filename: "index.html"
        })
    ]
}