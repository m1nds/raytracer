{ pkgs ? import <nixpkgs> {} }:

with pkgs;

mkShell {
    buildInputs = [
        pkgs.cmake
        pkgs.clang
    ];
}
