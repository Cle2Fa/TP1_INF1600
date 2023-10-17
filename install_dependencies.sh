#!/bin/bash

# Detect the Linux distribution
DISTRO=$(grep '^ID=' /etc/os-release | cut -d'=' -f2 | tr -d '"')

# Install the required packages based on the detected distribution
case $DISTRO in
    "fedora")
        sudo dnf update
        sudo dnf install -y make glibc-devel.i686
        ;;
    "ubuntu")
        sudo apt update
        sudo apt install -y make libc6-dev:i386
        ;;
    *)
        echo "Unsupported distribution!"
        exit 1
        ;;
esac

# Check the exit status of the last command to determine success
if [ $? -eq 0 ]; then
    echo "OKAY, PROJECT DEPENDENCIES FULFILLED CORRECTLY. PLEASE PROCEED."
else
    echo "FATAL FAILURE IN GETTING DEFAULT DEPENDENCIES. WARNING."
    exit 1
fi
