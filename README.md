# Assignment02-Gnuplot
# Console Application: Geometric Figures

This README provides an overview of the directory structure and contents of the project, outlining the purpose and organization of each folder.

## Folder Structure

1. **src**:
   - Contains the source code files of the project, including modules, classes, functions, and other relevant code artifacts necessary.

2. **lib**:
   - Houses dependencies required by the project, serving as a repository for third-party code utilized within the project.

3. **objectFiles**:
   - Stores compiled object files generated during the build process, typically resulting from compiling source code files and serving as an intermediate step in the creation of executable or binary files.

4. **output**:
   - Contains the output files generated by the project.

5. **test**:
   - Contains test suites and related files used for testing the functionality and integrity of the project.

## Running the Application

To run this application:

- Navigate to the `output` folder and execute `main`.
- Alternatively, navigate to the `test` folder and run the following commands:
  - `g++ main.cpp -o main.exe -I ../headers -L ../lib -l lib`
  - `main`
