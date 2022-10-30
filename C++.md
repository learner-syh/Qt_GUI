# c++学习笔记

## 参考资料
   1. c++primer
   2. [cs106L的阅读材料](https://web.stanford.edu/class/cs106l/full_course_reader.pdf)
   3. cs106L的slide和视频
   
## 1. type and struct
   1. Everything with a name in your program has a type
   2. Strong type systems prevent errors before your code runs!
   3. Structs are a way to bundle a bunch of variables of many types
   4. std::pair is a type of struct that had been defined for you and is in the STL
   5. So you access it through the std:: namespace (std::pair)
   6. auto is a keyword that tells the compiler to deduce the type of a variable, it should be used when the type is obvious or very cumbersome to write out

   
## 2. stream

>- STL = Standard Template Library
>- Contains TONS of functionality (algorithms, containers, functions, iterators) some >  of which we will explore in this class
>- The namespace for the STL is std
>- std is the abbreviation for standard
>- IDK why they didn’t name the namespace stl
>- So to access elements from the STL use std::

   1. stream: an abstraction for input/output. Streams convert between data and 
    the string representation of data.
   2. std::cout is a global constant object that you get from `#include<iostream>`
    To use any other output stream, you must first initialize it!
   3. **somesting about std::cin**
- First call to std::cin >> creates a command line prompt 
that allows the user to type until they hit enter
- Each >> ONLY reads until the next whitespace
- Whitespace = tab, space, newline
- Everything after the first whitespace gets saved and used the 
next time std::cin >> is called
- The place its saved is called a buffer!
- If there is nothing waiting in the buffer, std::cin >>
creates a new command line prompt
- Whitespace is eaten: it won’t show up in output

4. **std::getline(istream& is, string& str, char delim)**
- How it works:
- Clears contents in str
- Extracts chars from is and stores them in str until: 
- End of file condition on is, sets EOF bit (can be checked 
using is.eof())
- Next char in is is delim, extracts but does not store delim
- str max size is reached, sets FAIL bit (can be checked using 
is.fail())
- If no chars extracted for any reason, FAIL bit set
5. **notice** Don’t mix >> with getline!
- " >> "reads up to the next whitespace character and does not go 
past that whitespace character.
- getline reads up to the next delimiter (by default, ‘\n’), and 
does go past that delimiter.
- ==Don’t mix the two or bad things will happen!==
6. ifstream
   ``` c++{.line-numbers}
   std::ifstream in(“out.txt”);// in is now an ifstream that reads from out.txt
   string str;
   in >> str; // first word in out.txt goes into str
   ```
7. **Recap**
- Streams convert between data of any type and the string 
representation of that data
- Streams have an endpoint: console for cin/cout, files for i/o fstreams, 
string variables for i/o streams where they read in a string from or 
output a string to.
- To send data (in string form) to a stream, use stream_name << 
data
- To extract data from a stream, use stream_name >> data, and 
the stream will try to coThe same as the other i/ostreams you’ve seen
==疑问：iostream和stringstream区别有吗？106L写的是：The same as the other i/ostreams you’ve seen==
 
