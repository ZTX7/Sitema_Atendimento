# Project - Data Structures

This project is proposed by Professor Pedro Kilansky in the Data Structures course at Uniruy Wyden University Center.

The purpose is to teach algorithms and complex structures in everyday programming.

### Project Members:

<table>
    <thead>
        <tr>
            <th>Name</th>
            <th>Registration Number</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>Sinézio da Silva Ramos Junior</td>
            <td>202302375081</td>
        </tr>
        <tr>
            <td>So-and-so</td>
            <td>So-and-so's Registration Number</td>
        </tr>
    </tbody>
</table>

## Project Structure
This project is organized as follows:

* **build/:** Contains the main.exe executable file that is generated after compiling the source code.

* **include/:** Stores the header files (.h), which declare functions and structures used in the project.

* **source/:** Contains the source code files (.cpp), where the main program logic is implemented.

## How to Set Up the Development Environment

To run this project in VS Code, you need to have the following tools installed:

### VS Code C/C++ Extension:

This extension is essential for compiling and debugging C and C++ projects in the editor. To install, open VS Code, go to the Extensions tab (or press Ctrl+Shift+X), search for "C/C++," and click Install.

### MinGW (Minimalist GNU for Windows):
This is a set of development tools that includes the GCC/G++ compiler. You can download it and follow the installation instructions on the official VS Code website.

## How to Compile and Run the Code
Follow these steps to generate the executable and run the project:

* Open the VS Code integrated terminal.

* Run the following command to compile the code and generate the main.exe file in the build folder:

```
g++ (Get-ChildItem source\*.cpp) -Iinclude -o build\main.exe
```
After the command is executed, the main.exe file will be available in the build folder.

* To run the program, navigate to the build folder in the terminal and type the executable name:

```
./build/main.exe
```
Enviar feedback
Painéis laterais
Histórico
Salvas