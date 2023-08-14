# Jotform-api-qt

A C++/Qt Client library for the [JotForm API](http://api.jotform.com/docs/).

## Installation

This library requires Qt6 to be installed.

### Unix-style

```bash
cd jotform-qt-api
mkdir build
cd build
cmake ../
cmake --build .
cmake --install .
```

After installation:

- Include the header in your project.
- Add the produced `.dll` or `.so` file and the relevant header to the path so your project can find it.
- Include the library in your project's CMake using `target_link_libraries(executable PRIVATE jotform)`.

## Authentication

To use the JotForm API, an API key is required for all user-related calls. You can generate your API Keys in the [API section](http://www.jotform.com/myaccount/api) of the My Account page on JotForm.

## Features

This library is currently under construction, so some features may be missing.

- [x] GET methods.
- [ ] POST methods.
- [ ] PUT methods.
- [ ] DELETE methods.
- [ ] Filtering submissions and forms by date.
