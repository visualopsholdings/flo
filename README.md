# flo

Welcome to f(lo). A functional language expressed in JSON.

## Prerequsists

#### Linux

```
sudo apt-get install -y git g++ gcc build-essential git make \
  pkg-config cmake  libssl-dev ruby-bundler xclip xsel libyaml-cpp-dev
```

### CMake

We need CMake 3.30.

#### Linux

```
sudo apt remove -y --purge --auto-remove cmake
```

#### From source
```
wget https://cmake.org/files/v3.30/cmake-3.30.5.tar.gz
tar -xzvf cmake-3.30.5.tar.gz
cd cmake-3.30.5
./bootstrap
make -j$(nproc)
sudo make install
```

### Boost

#### from source

```
wget https://github.com/boostorg/boost/releases/download/boost-1.85.0/boost-1.85.0-b2-nodocs.tar.gz
tar xzf boost-1.85.0-b2-nodocs.tar.gz 
cd boost-1.85.0
./bootstrap.sh --prefix=/usr/local
sudo ./b2 install boost.stacktrace.from_exception=off
```

### cpp-reflect

#### from source

##### On the Mac

```
brew install bison yaml-cpp pkg-config
```

##### on any platform

```
git clone https://github.com/getml/reflect-cpp.git
cd reflect-cpp
git submodule update --init
./vcpkg/bootstrap-vcpkg.sh # Linux, macOS
./vcpkg/bootstrap-vcpkg.bat # Windows
cmake -S . -B build -DCMAKE_CXX_STANDARD=20 -DCMAKE_BUILD_TYPE=Release -DREFLECTCPP_YAML=ON
cmake --build build -j 4 # gcc, clang
cmake --build build --config Release -j 4 # MSVC
cd build
sudo make install
```

## Building and testing

Build this project:

```
git clone https://github.com/visualops/flo.git
cd flo
mkdir build
cd build
cmake ..
make
make test
```

## Usage

Flo is a simple tool that will take a JSON (or YAML) file and transform it using another JSON (or YAML) file which
contains the "program" for the JSON.

If hello.json was:
```
{
  "message": "hello"
}
```

And hello-t.json was:
```
{
  "library": [
    {
      "name": "messageIsHello",
      "result": {
        "equal": [
          { "getmember": { "name": "message" } },
          { "string": "hello" }
        ]
      }
    }
  ],
  "transform": {
    "select": [
      {
        "if": {
          "p": {
            "messageIsHello": {}
          },
          "then": {
            "setmember": {
              "name": "message",
              "value": { "string": "world" }
            }
          }
        }
      },
      {
        "null": {}
      }
    ]
  }
}
```

And you ran:
```
cat hello.json | ./flo hello-t.json
```

It would output:
```
{
    "message": "world"
}
```

If you had another file called message.json like this:
```
{
  "message": "a message"
}
```

Then when you ran:
```
cat message.json | ./flo hello-t.json
```

It would output:
```
{
    "message": "a message"
}
```

So it would leave the contents alone. That's what the "null": {} at the bottom of the "select": [] is for.

## Functions

### select

This will loop through the block, and return the first one which returns a value.

### pass

Loop through the block, ignore all returns and return the last ones value.

### if

This function takes the "p" (predicate), determines if it is true, and if so it returns the "then".

There is no "else".

It is almost always used in a select.

### equal

Loop through the blocks and test if they are all the same as the first block. There can be any 
number.

### getmember

Lookup the member of a dictionary with the "name" and return it's value.

### string

Simply return the value as a string.

### setmember

Set the member of a dictionary with the "name" to a value.

### null

Just pass the content through.

### apply

This will loop through the blocks, applying each transform in sequence.

### cur

When applying, this returns the current element.

### dict

Takes the contents of the function and return a dictionary. You can also use apply to
convert a list of string pair lists into a dictionary for dynamic code.

### true

A value representing true.

## Scenarios

You can run a transform on it's own without any imput file by specifying a scenario in the file
that you want to run. This is how you do testing.

So the our original file could have something like this at the bottom of it.

```
{
  "library": [
    ...
  ],
  "transform": {
    ...
  },
  "scenarios": [
    {
      "name": "Simple",
      "input": {
        "message": "hello"
      }
    }
  ]  
}
```

Now if we run that with this:

```
./flo hello-t.json --transform=Simple
```

Then it would run standalone :-) This is how you do TDD on flo.

## YAML

Your inputs can also be yaml, not JSON.

```
cat hello.yml | ./flo apply-t.yml
```

hello.yml:
```
---
message: hello
```

apply-t.yml
```
library:
- name: pubKey
  result:
    string: a key
- name: x
  result:
    string: x
transform:
  apply:
  - - - type
      - online
    - - build
      - '32999'
    - - headerTitle
      - DSurfer
    - - pubKey
      - pubKey: {}
  - dict: {}
```

## License

Flo is licensed under [version 3 of the GNU General Public License] contained in LICENSE.

## Change Log

### 27-May-2024

It starts.

### 30-May-2024

Implement null, if, true, dict, string, getmember and equal.

### 31-May-2024

- Implement setmember and select.

### 12-Oct-2025

- Switch to using cppreflect.

### 13-Oct-2025

- Add in namespaces.

### 14-Oct-2025

- Add in apply and make dict able to be a monad.

### 15-Oct-2025

- Add in cur and pass.

### 21-Oct-2025

- Add license and make public.

### 23-Oct-2025

- Formalise support for scenarios and cleanup.
- Add in YAML support.
- flo processes std in.
