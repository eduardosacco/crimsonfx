#!/bin/bash

source ${0%/*}/utils/common.sh

check_env_vars

# prepare environment
$UTILS_DIR/init-common.sh
$UTILS_DIR/synchronize-toolchain.sh
cd_root

download_sysroot_minimal
download_qtrpi_binaries

