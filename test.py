import subprocess
import os

#py2output = subprocess.check_output(['echo','$skimDir'],shell=True).decode("ascii")
#py2output = os.sys(['echo','$skimDir'])

#print 'py2 said: {}'.format(py2output)
print os.environ["skimDir"]
