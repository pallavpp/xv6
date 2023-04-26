## Description
- Lab 2A: Extend the kernel to support Caret navigation (text cursor navigation) and add partial support of "Shell History Ring".
- Lab 2B: Add First come - First Served, Multi-Level Queue and Dynamic Multi-Level Queue scheduling and their respective sanity tests.

Exact problem statement can be found in the PDFs.

Solution for each lab is in the respective folders. Each folder contains the patch file for solution and a report explaining the solution. The modified files are also present in the folder and can be replaced with the original xv6 files in case the patch file does not work. Files modified for each task individually can be found in the subfolders.

### To use the patch file:
- Keep the xv6 cloned repo and the solution patchfile.patch in the same directory. (Preferably a new folder in desktop to avoid errors). The original xv6 repo can be found [here](https://github.com/mit-pdos/xv6-public).
- Open this parent directory (that contains patch and xv6) in the terminal and run the following command - `patch -s -p0 < patchfile.patch`
- The xv6-public folder will now have all the required changes.
