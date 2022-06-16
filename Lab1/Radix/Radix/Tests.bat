set PROGRAM="%~1"

rem ��� ������� ��� ���������� ��������� ��������� ��� ��������
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err
echo non argument test passed

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������
%PROGRAM% 10 16 65535 > "%TEMP%\output.txt"
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\output.txt" "tests\FFFF.txt" > nul
if ERRORLEVEL 1 goto err
echo base test passed

rem ��� ������� � ������������� ��������� ��������� ������� ��� ��������
%PROGRAM% 10 16 -65535 > "%TEMP%\output.txt"
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\output.txt" tests\-FFFF.txt > nul
if ERRORLEVEL 1 goto err
echo minus test passed

rem ��������� 0 ��������� ������� ��� ��������
%PROGRAM% 10 16 0 > "%TEMP%\output.txt"
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\output.txt" tests\0.txt > nul
if ERRORLEVEL 1 goto err
echo zero test passed

rem ��� ������� �� ��������� ���� ������������� ��������� ������� ��� ��������
%PROGRAM% 10 36 2147483648 > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto err
echo max int test passed

rem ��� ������� � ������������� ���������� ��������� ������� ��� ��������
%PROGRAM% -10 -36 10 > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto err
echo minus notation test passed

echo OK
exit 0

:err
echo Program testing failed
exit 1