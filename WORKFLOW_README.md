# Release Build Workflow

This repository now includes a GitHub Action workflow for creating manual releases.

## How to Use

1. Go to the "Actions" tab in the GitHub repository
2. Select "Build Release" workflow
3. Click "Run workflow"
4. Fill in the required parameters:
   - **Release tag**: Version tag (e.g., `v1.0.0`)
   - **Release name**: Human-readable name (e.g., `PCSX ReARMed v1.0.0`)
   - **Prerelease**: Check if this is a prerelease/beta version

## What It Does

The workflow will:
1. Check out the code with all submodules
2. Install build dependencies (SDL 1.2, ALSA, libpng, zlib)
3. Configure the build using `./configure`
4. Build the project using `make -j$(nproc)`
5. Create a release package using `make rel`
6. Upload the build artifact for download
7. Create a GitHub release with the built package

## Output

The workflow produces:
- A Linux x86_64 release package (`pcsx_rearmed_{version}_linux-x86_64.zip`)
- A GitHub release with the package attached
- Build artifacts available for 30 days

## Package Contents

The release package includes:
- `pcsx` - Main emulator executable
- `plugins/` - GPU and SPU plugins
  - `gpu_neon.so` - NEON-optimized GPU plugin
  - `gpu_peops.so` - P.E.Op.S. GPU plugin  
  - `gpu_unai.so` - Unai GPU plugin
  - `gpu_gles.so` - OpenGL ES GPU plugin
  - `spunull.so` - Null SPU plugin
- `bios/` - Directory for PlayStation BIOS files
- `skin/` - UI skin files
- `readme.txt` - Documentation
- `COPYING` - License information

## System Requirements

The built package requires:
- Linux x86_64
- SDL 1.2 library
- ALSA or PulseAudio for audio
- Optional: OpenGL ES for GPU acceleration