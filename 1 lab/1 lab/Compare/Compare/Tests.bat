@echo off

SET Program="%~1"
set SuccessfulTests=0

if %Program%=="" (
	echo Please specify path to program compare.exe
	exit /B 1
)

echo Running Tests...

REM 1 ����
%Program% "" "Test/inp1.txt" "%TMP%\output.txt" > nul && goto err
echo Test 'input1 not provided' successful
set /A successful+=1

REM  2 ����
%Program% "Test/inp1.txt" "" "%TMP%\output.txt" > nul && goto err
echo Test 'input2 not provided' successful
set /A successful+=1

REM  ��� �����
%Program% "" "" "%TMP%\output.txt" > nul && goto err
echo Test 'both input file not provided' successful
set /A successful+=1

REM ��� ����������
%Program% > nul && goto err
echo Test 'it doesn't work without args' successful
set /A successful+=1

REM ����������
%Program% "Test/inp1.txt" "Test/input1.txt" || goto err
echo Test 'equal file' successful
set /A successful+=1

REM ������
%Program% "Test/inp2.txt" "Test/input2.txt" || goto err
echo Test 'not equal file' successful
set /A successful+=1

REM ������ �����
%Program% "Test/inp3.txt" "Test/input3.txt" || goto err
echo Test 'empty files' successful
set /A successful+=1

REM �����
echo Tests passed: %successful%/7
echo All tests successful
exit /B 0

REM Test failed
:err
echo Test failed!
exit /B 1