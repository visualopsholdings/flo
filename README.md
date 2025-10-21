# flo

Welcome to f(lo). A functional language expressed in JSON.

## Usage

Flo is a simple tool that will take a JSON file and transform it using another JSON file which
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
  "select": [
    {
      "if": {
        "p": {
          "equal": [
            { "getmember": { "name": "message" } },
            { "string": "hello" }
          ]
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
```

And you ran:
```
./flo hello-t.json hello.json 
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
./Flo hello-t.json message.json 
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

