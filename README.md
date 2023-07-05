g722_1_mod
==============

|      CI              | status |
|----------------------|--------|
| pip builds           | [![Pip Actions Status][actions-pip-badge]][actions-pip-link] |
| [`cibuildwheel`][]   | [![Wheels Actions Status][actions-wheels-badge]][actions-wheels-link] |

[actions-badge]:           https://github.com/adafruit/g722_1_mod/workflows/Tests/badge.svg
[actions-pip-link]:        https://github.com/adafruit/g722_1_mod/actions?query=workflow%3A%22Pip
[actions-pip-badge]:       https://github.com/adafruit/g722_1_mod/workflows/Pip/badge.svg
[actions-wheels-link]:     https://github.com/adafruit/g722_1_mod/actions?query=workflow%3AWheels
[actions-wheels-badge]:    https://github.com/adafruit/g722_1_mod/workflows/Wheels/badge.svg

Installation
------------

 - clone this repository
 - `pip install ./g722_1_mod`

Building the documentation
--------------------------

Documentation for the example project is generated using Sphinx. Sphinx has the
ability to automatically inspect the signatures and documentation strings in
the extension module to generate beautiful documentation in a variety formats.
The following command generates HTML-based reference documentation; for other
formats please refer to the Sphinx manual:

 - `cd g722_1_mod/docs`
 - `make html`

License
-------

g722\_1\_mod is provided under a BSD-style license that can be found in the LICENSE
file. By using, distributing, or contributing to this project, you agree to the
terms and conditions of this license.

[`cibuildwheel`]:          https://cibuildwheel.readthedocs.io
