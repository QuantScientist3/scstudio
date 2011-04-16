# set the default LPSOLVE_ROOT value
IF(NOT LPSOLVE_ROOT)
  SET(LPSOLVE_ROOT $ENV{LPSOLVE_ROOT} CACHE PATH "The LPSOLVE directory root.")
ENDIF(NOT LPSOLVE_ROOT)

FIND_LIBRARY(LPSOLVE_LIBRARY
  NAMES lpsolve55
  PATHS
    ${LPSOLVE_ROOT}
    ${LPSOLVE_ROOT}/lib
  DOC "The lp_solve library")

FIND_PATH(LPSOLVE_INCLUDE_DIR
  NAMES lp_lib.h
  PATHS
    ${LPSOLVE_ROOT}
    ${LPSOLVE_ROOT}/include/lpsolve
  DOC "The lp_solve include files")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(lp_solve DEFAULT_MSG
  LPSOLVE_LIBRARY LPSOLVE_INCLUDE_DIR)
