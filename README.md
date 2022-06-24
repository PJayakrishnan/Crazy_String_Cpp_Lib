# CPP static library to work on strings
Contents:
* [How to compile the library](#how-to-compile-the-library)
* [How to add CrazyStringLib library in a project using Visual Studio](#how-to-add-crazystringlib-library-in-a-project-using-visual-studio)
* [Functions](#functions)




# How to compile the library
You can clone this github repo to your local system using Visual Studio and open the `.sln` file there. Thus you will be able to compile and build `.lib` file.

# How to add CrazyStringLib library in a project using Visual Studio

You can copy the `.h` and `.lib` files to a folder inside the project you want this library to serve for and give both the file's relative paths in  project properties at  respective locations.
### You should add header file like,
````C++
#include "include/crazy_string_lib.h"
````

when it is placed inside a folder, say `include` in the project directory.
# Functions
## 1. WhichAreDiffPositions

`WhichAreDiffPositions` in CrazyStringLib library will let you compare two strings on character by character basis. You can input two strings and the function will return a vector of positions where characters of strings do not match. 



|Indeces    | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 10  | 11  |
|:---       |:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|Text One   | H   | E   | L   | L   | O   | W   |     | W   | O   | R   | L   | D   |
|Text Two   | H   | E   | L   | O   |     | W   | O   | R   | L   | D   | \0  | \0  |
|Difference |     |     |     | 3   | 4   |     | 6   | 7   | 8   | 9   | 10  | 11  |


Here we are comparing "HELO WORLD" and "HELLOW WORLD". Since the larger text has 12 characters, library function will frame both  texts into a container of 12 characters. The two free spaces of the smaller text will be filled with '\0'. Now each element of both  texts are compared and the postion indeces of the container is added to a list if the elements do not match. **_Indexing of container is Zero based_**. In our example container positions at 3, 4, 6, 7, 8, 9, 10, 11 will be in the output list as their elements would not match.


### You can call the function like

````C++
std::vector<int> differenceVector = CrazyStringLib::WhichAreDiffPositions(textOne,textTwo);
````

`differenceVector` will contain the positions of container where difference is found when compared.




## 2. WhereAllMyChar

`WhereAllMyChar` function in CrazyStringLib library will find the positions(indeces) in a string/text where given character is found. For example, lets say we need to find the positions of character `'l'` in the string `"Hello world"`. Calling `WhereAllMyChar` with `"Hello world"` and `'l'` as arguments will return a vector of integers with values 2, 3, and 9. Positions/Indeces are zero based. The function is case sensitive.
### You can call the function like

````C++
std::vector<int> pos = CrazyStringLib::WhereAllMyChar(text,character);
````
`pos` will have all the positions (indeces) where given character is found in the given string/text.
