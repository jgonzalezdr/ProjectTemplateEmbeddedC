CMake Embedded Project Template
===========
[![Build status](https://ci.appveyor.com/api/projects/status/7hr9hgjg3qknrsed/branch/main?svg=true)](https://ci.appveyor.com/project/jgonzalezdr/projecttemplateembeddedc/branch/main)
[![codecov](https://codecov.io/gh/jgonzalezdr/ProjectTemplateEmbeddedC/branch/main/graph/badge.svg)](https://codecov.io/gh/jgonzalezdr/ProjectTemplateEmbeddedC)
[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2Fjgonzalezdr%2FProjectTemplateEmbeddedC.svg?type=shield)](https://app.fossa.com/projects/git%2Bgithub.com%2Fjgonzalezdr%2FProjectTemplateEmbeddedC?ref=badge_shield)
## About

This repository is just a template for an embedded project which at least its unit tests are built using [CMake](https://cmake.org/), and using [cpputest](http://cpputest.github.io/) for unit test execution.

## Usage

1.  Download all the [files from this repository as a ZIP file](https://github.com/jgonzalezdr/projecttemplateembedded/archive/main.zip) and unzip them to your project base directory.

> The _main_ branch is populated with some example files. You may download a [version without any examples](https://github.com/jgonzalezdr/projecttemplatelib/archive/unpopulated.zip) from the _unpopulated_ branch.

2. Edit the top level `CMakeLists.txt` and replace _ProjectTemplateEmbedddedC_ in the project command with your own project name (leave the .Top suffix).

3. Put the headers and the implementation files for production code in `production/sources/`.

4. Edit `production/CMakeLists.txt` and replace _ProjectTemplateEmbedddedC_ in the project command with your own project name (this time without the ".Top" suffix). This will be the base name for a library file that will be generated for checking production code compilation in host. You may also update your project version in the project command.

5. Edit `production/CMakeLists.txt` and set the list of production source and header files that will be tested in host, as well as the header files for any external libraries (e.g., HAL libraries), and modify any other parameters that you like.

6. External libraries header files may not be suitable for mocking (e.g., they have inline code that directly accesses memory-mapped SFRs). In that case you will need to create a mockable abstraction layer between your code and those libraries.

7. If the production code to be tested includes a `main()` function, ensure that its name is replaced using precompilation macros for a suitable name that does no clash with the unit tests own main function (e.g, change it to `production_main()`).

7. Add your common mocks and expectation functions to `test/Mocks` (both for your own modules and for external libraries).

8. To create unit tests, copy the `test/TestTemplate/` directory to another directory under `test/` renaming it with the test name, then:
   - Rename the test implementation file `TestModule_test.cpp` according to your test module name (It's recommended to leave the _ _test_ suffix).
   - Edit the test's `CMakeLists.txt`:
       - Replace _ProjectTemplateEmbedddedC_ and _TestModule_ in the project command with your own project name and test module name (e.g. "_YourProjectName_.Test._YourTestModuleName_").
       - Set the list of production source files to be tested, and the list of test source files (test, mocks, other test helper functions, etc.).
   - Edit the test implementation file to add your tests.

9. Edit `test/CMakeLists.txt` and add all the subdirectories for your tests.

10. Delete all example files and directories from the `test/` and `production/` directories.

11. Replace `LICENSE.txt` with your project's license file.

12. Create a build directory under the top directory (e.g. `build/`), and inside it execute `cmake .. G "<GeneratorOfYourChoice>"` (add any other configuration options that you like).

13. Modify `appveyor.yml` (or delete it) according to your continouous integration needs.

## CMake Project Options

| OPTION                | Description |
| -                     | - |
| `-DCMAKE_BUILD_TYPE`  | Selects build type<br>_(only for single-config generators)_<br>`Debug`<br>`Release`_(default)_<br>`RelWithDebInfo` (Release with debug info)<br>`MinSizeRel`(Release with size optimization)<br> `Coverage`(Debug with code coverage enabled) |
| `-DBUILD_TESTING`     | Enables compilation and execution of tests<br>`ON`_(default)_<br>`OFF` |
| `-DCPPUTEST_HOME`     | Path to your CppUTest installation directory<br>`<filesystem path>` |
| `-DLCOV_HOME`         | Path to your LCOV installation directory<br>`<filesystem path>` |
| `-DCOVERAGE`          | Enables code coverage in tests<br>_(only for multi-config generators)_<br>`ON`_(default)_<br>`OFF` |
| `-DCOVERAGE_VERBOSE`  | Enables verbose code coverage<br>`ON`<br>`OFF`_(default)_ |
| `-DCI_MODE`           | Enables Continous Integration mode<br>`ON`<br>`OFF`_(default)_ |

## Requirements

- [cmake](https://cmake.org/) (≥ v3.3, tested with v3.22.2)
- [CppUTest](http://cpputest.github.io/) [Optional, not needed if tests are disabled] (≥ v4.0, tested with [v4.0-gdr0](https://github.com/jgonzalezdr/cpputest/releases/tag/v4.0-gdr0))
- On Windows:
  - A C/C++ compiler, either:
    - [MinGW-w64](https://sourceforge.net/projects/mingw-w64/) (tested with v7.3.0, v8.1.0, [TDM-GCC v9.2.0](https://jmeubank.github.io/tdm-gcc/download/) and [TDM-GCC v10.3.0](https://jmeubank.github.io/tdm-gcc/download/))
    - [Microsoft Visual Studio](https://www.visualstudio.com/es/downloads/) (tested with Visual Studio Community 2019 and 2022)
  - [LCOV for Windows](https://github.com/jgonzalezdr/lcov/releases) [Optional, needed if tests and coverage are enabled using MinGW] (tested with [v1.15.alpha1w](https://github.com/jgonzalezdr/lcov/releases/download/v1.15.alpha1w/lcov-v1.15.alpha1w.zip))
  - [OpenCppCoverage](https://github.com/OpenCppCoverage/OpenCppCoverage) [Optional, needed if tests and coverage are enabled using Visual Studio] (tested with v0.9.8.0)
- On Linux:
  - [GCC](https://gcc.gnu.org/) (tested with v7.5.0, v8.4.0 and v9.3.0)
  - [LCOV](http://ltp.sourceforge.net/coverage/lcov.php) [Optional, needed if tests and coverage are enabled using GCC] (tested with v1.14)


## License
[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2Fjgonzalezdr%2FProjectTemplateEmbeddedC.svg?type=large)](https://app.fossa.com/projects/git%2Bgithub.com%2Fjgonzalezdr%2FProjectTemplateEmbeddedC?ref=badge_large)