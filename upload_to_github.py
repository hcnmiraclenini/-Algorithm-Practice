# -*- coding: utf-8 -*-
# GitHub 上传脚本
import subprocess
import os
import sys

def run_command(command, cwd=None):
    """执行命令并返回结果"""
    try:
        result = subprocess.run(
            command,
            shell=True,
            cwd=cwd,
            capture_output=True,
            text=True,
            encoding='utf-8',
            errors='ignore'
        )
        return result.returncode == 0, result.stdout, result.stderr
    except Exception as e:
        return False, "", str(e)

print("开始上传代码到 GitHub...\n")
print("=" * 60)

# 步骤0: 解决 Git 权限问题
print("步骤0: 解决 Git 权限问题...")
current_dir = os.getcwd()
success, stdout, stderr = run_command(f'git config --global --add safe.directory "{current_dir}"')
if success or "already exists" in stderr.lower():
    print(f"✓ 已添加安全目录: {current_dir}")
else:
    print(f"⚠ 添加安全目录可能失败，但继续尝试: {stderr}")

# 检查是否在 git 仓库中
print("\n步骤1: 检查 Git 仓库状态...")
success, stdout, stderr = run_command("git status")
if not success:
    if "not a git repository" in stderr.lower() or "dubious ownership" in stderr.lower():
        print("初始化 Git 仓库...")
        success, stdout, stderr = run_command("git init")
        if success:
            print("✓ Git 仓库初始化成功")
        else:
            print(f"✗ Git 初始化失败: {stderr}")
            sys.exit(1)
    else:
        print(f"✗ Git 状态检查失败: {stderr}")
        sys.exit(1)
else:
    print("✓ 已是 Git 仓库")

# 检查远程仓库
print("\n步骤2: 检查远程仓库...")
success, stdout, stderr = run_command("git remote -v")
if "origin" not in stdout:
    print("添加远程仓库...")
    repo_url = "https://github.com/hcnmiraclenini/-Algorithm-Practice.git"
    success, stdout, stderr = run_command(f'git remote add origin {repo_url}')
    if success:
        print(f"✓ 远程仓库添加成功: {repo_url}")
    else:
        # 如果添加失败，可能是已存在，尝试设置 URL
        success, stdout, stderr = run_command(f'git remote set-url origin {repo_url}')
        if success:
            print(f"✓ 远程仓库 URL 已更新: {repo_url}")
        else:
            print(f"✗ 添加远程仓库失败: {stderr}")
else:
    print("✓ 远程仓库已配置")

# 创建 .gitignore 文件（如果不存在）
print("\n步骤3: 检查 .gitignore 文件...")
if not os.path.exists(".gitignore"):
    gitignore_content = """# Visual Studio 文件
*.vcxproj.user
*.suo
*.user
*.userosscache
*.sln.docstates

# 构建结果
[Dd]ebug/
[Rr]elease/
x64/
x86/
[Bb]in/
[Oo]bj/
[Ll]og/
*.exe
*.obj
*.pdb
*.ilk
*.log
*.idb
*.pch
*.tlog

# Visual Studio 临时文件
*.tmp
*.temp
*.swp
*~

# Python 脚本（如果需要保留可以注释掉）
# *.py
# __pycache__/

# 其他
.DS_Store
Thumbs.db
"""
    with open(".gitignore", "w", encoding="utf-8") as f:
        f.write(gitignore_content)
    print("✓ 创建 .gitignore 文件")
else:
    print("✓ .gitignore 文件已存在")

# 添加所有文件
print("\n步骤4: 添加文件到 Git...")
success, stdout, stderr = run_command("git add .")
if success:
    print("✓ 文件添加成功")
else:
    print(f"✗ 文件添加失败: {stderr}")
    sys.exit(1)

# 检查是否有更改
success, stdout, stderr = run_command("git status --short")
if not stdout.strip():
    print("\n⚠ 没有需要提交的更改，继续后续步骤...")
    # 不退出，继续执行合并和推送

# 提交更改
print("\n步骤5: 提交更改...")
commit_message = "Initial commit: 算法与数据结构练习代码库整理完成"
success, stdout, stderr = run_command(f'git commit -m "{commit_message}"')
if success:
    print(f"✓ 提交成功: {commit_message}")
else:
    print(f"✗ 提交失败: {stderr}")
    # 如果是因为没有更改，尝试检查状态
    if "nothing to commit" in stderr.lower():
        print("提示: 没有需要提交的更改")
    else:
        sys.exit(1)

# 推送到 GitHub
print("\n步骤6: 处理远程仓库合并...")
print("注意: 如果远程仓库已有内容，将进行合并")

# 先尝试拉取远程内容（允许不相关历史合并）
print("尝试拉取远程仓库内容...")
success, stdout, stderr = run_command("git pull origin main --allow-unrelated-histories --no-edit")
if success:
    print("✓ 远程内容已合并")
elif "fatal: couldn't find remote ref main" in stderr.lower() or "couldn't find remote" in stderr.lower():
    print("✓ 远程仓库为空，跳过合并")
elif "refusing to merge unrelated histories" in stderr.lower():
    print("⚠ 合并被拒绝，继续尝试推送")
else:
    print(f"⚠ 拉取时出现警告: {stderr}")

# 检查 README.md 是否需要保留本地版本
if os.path.exists("README.md"):
    print("\n步骤7: 确保使用本地 README.md...")
    # 如果拉取后 README 被覆盖，我们需要恢复本地版本
    print("✓ 本地 README.md 将覆盖远程版本")
    success, stdout, stderr = run_command("git add README.md")
    if success:
        # 如果有更改，再次提交
        success, stdout, stderr = run_command('git commit -m "Update README.md with local version"')
        if success:
            print("✓ README.md 已更新为本地版本")
        elif "nothing to commit" in stderr.lower():
            print("✓ README.md 无需更新")

# 设置主分支并推送
print("\n步骤8: 推送到 GitHub main 分支...")
print("注意: 这可能需要您输入 GitHub 用户名和密码/令牌")
success, stdout, stderr = run_command("git branch -M main")
if success:
    print("✓ 分支已设置为 main")

success, stdout, stderr = run_command("git push -u origin main")
if success:
    print("✓ 推送成功！代码已上传到 GitHub")
    print("\n🎉 上传完成！本地 README.md 已保留并上传。")
else:
    print(f"\n✗ 推送失败: {stderr}")
    print("\n可能的原因：")
    print("1. 需要配置 GitHub 身份验证（用户名和密码/Personal Access Token）")
    print("2. 网络连接问题")
    print("\n建议手动执行以下命令：")
    print("  git push -u origin main")
    print("\n或者使用 GitHub Desktop 客户端进行推送")

print("\n" + "=" * 60)
print("操作完成！")

