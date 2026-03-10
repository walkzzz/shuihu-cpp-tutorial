# 水浒聚义寨 C++ 教程 - 快速构建脚本
# 使用 PowerShell 运行

Write-Host "🏮 水浒聚义寨 C++ 教程 - 构建脚本" -ForegroundColor Cyan
Write-Host "=================================" -ForegroundColor Cyan

$ErrorActionPreference = "Stop"

# 创建构建目录
if (Test-Path "build") {
    Remove-Item "build" -Recurse -Force
}
New-Item -ItemType Directory -Path "build" | Out-Null

# 配置
Set-Location build
cmake .. -G "Visual Studio 17 2022"
if ($LASTEXITCODE -ne 0) {
    Write-Host "❌ CMake 配置失败" -ForegroundColor Red
    exit 1
}

# 构建
Write-Host "`n🔨 开始构建..." -ForegroundColor Yellow
cmake --build . --config Release
if ($LASTEXITCODE -ne 0) {
    Write-Host "❌ 构建失败" -ForegroundColor Red
    exit 1
}

Write-Host "`n✅ 构建完成!" -ForegroundColor Green
Write-Host "`n运行示例:" -ForegroundColor Cyan
Write-Host "  .\build\Release\basic-01.exe"
Write-Host "  .\build\Release\intermediate-01.exe"
Write-Host "  .\build\Release\advanced-01.exe"
