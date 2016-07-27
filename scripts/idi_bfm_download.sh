# Script to download idi bfm source code
# Param 1: Version
# Param 2: Path to download

if [[ $# -ne 2 ]];
then
  echo "Missing argument. Need both source and destination paths."
  exit 1
fi

/p/dt/sde/tools/common/dtinstaller/latest/dtinstaller --install --platform em64t_SLES11 --tool uncore_bfm --version $1 --destination $2 --project Other --subtools
