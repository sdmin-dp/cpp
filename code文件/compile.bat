@echo off
chcp 65001 >nul
echo ====== 编译开始 ======
echo 正在编译: %1

REM 使用绝对路径的 g++
set MINGW_PATH=C:\msys64\mingw64\bin\g++
if exist "%MINGW_PATH%" (
    "%MINGW_PATH%" -std=c++11 -O2 -Wall -Wextra -Wno-sign-compare -Wno-unused-variable -o "%~dpn1.exe" "%1"
) else (
    REM 如果找不到指定路径，尝试 PATH 中的 g++
    g++ -std=c++11 -O2 -Wall -Wextra -Wno-sign-compare -Wno-unused-variable -o "%~dpn1.exe" "%1"
)

if %errorlevel% neq 0 (
    echo ❌ 编译失败！
    pause
    exit /b 1
)

echo ✅ 编译成功: %~n1.exe
echo ====== 运行程序 ======
echo.

"%~dpn1.exe"

if %errorlevel% neq 0 (
    echo.
    echo ⚠️ 程序返回非零退出码: %errorlevel%
)

echo.
echo ====== 运行结束 ======
pause