# litebrowser-haiku

This is a demonstration app for the litehtml implementation for Haiku.

This repository uses a submodule tracking my latest (develop) feature-haiku branch of the litehtml library.

## Build instructions

From within a Terminal in Haiku execute:-

```sh
git clone https://github.com/adamfowleruk/litebrowser-haiku.git
cd litebrowser-haiku
git pull
git submodule update --init
mkdir build
cd build
cmake ..
make
./litebrowser /path/to/my/file.html
```

Note: Git pull and git submodule update are there as you will need to execute these
to pick up changes on my development branch.

## References

- Haiku LiteHTML Container Implementation (LiteHtmlView : BView) - https://github.com/adamfowleruk/litehtml/tree/feature-haiku/containers/haiku
- litebrowser Cairo container implementation (for reference) - https://github.com/litehtml/litehtml/blob/master/containers/cairo/cairo_container.cpp
- litebrowser-linux (for reference) - https://github.com/litehtml/litebrowser-linux

## License

The code in this repository is licensed under the MIT license. See the LICENSE file for more details.

litehtml itself is licensed under the New BSD License, and uses components under the Apache-2.0 license.
