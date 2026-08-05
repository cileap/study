# GitHub 学习监督完全指南（从零开始）

## 一、核心名词解释（先把英文搞懂）

编程工具都是英文的，这些词你每天都会看到：

| 英文 | 读法 | 什么意思 | 类比 |
|------|------|----------|------|
| **Git** | /ɡɪt/ | 版本控制工具，安装在你的电脑上 | 就像 Word 的"修订记录"功能，但更强 |
| **GitHub** | /ɡɪt.hʌb/ | 网站，用来存放 Git 管理的代码 | 就像代码的百度网盘，但能看修改历史 |
| **repository (repo)** | /rɪˈpɒzɪtəri/ | 仓库，一个项目的存储空间 | 一个文件夹 + 它的所有历史版本 |
| **clone** | /kloʊn/ | 把网上的仓库下载到本地 | 复制粘贴，但保留了所有历史 |
| **commit** | /kəˈmɪt/ | 提交一次修改 | 游戏里的"存档"，给你当前的代码拍一张快照 |
| **push** | /pʊʃ/ | 把本地修改上传到 GitHub | 把存档上传到云端 |
| **pull** | /pʊl/ | 从 GitHub 下载最新修改到本地 | 从云端拉取别人更新过的存档 |
| **stage (add)** | /steɪdʒ/ | 暂存，选择哪些文件要提交 | 拍照前先选哪些东西要放进相框 |
| **branch** | /bræntʃ/ | 分支 | 书的草稿副本，不影响主线内容 |
| **main** | /meɪn/ | 主分支，默认就叫这个 | 你的"定稿"版本 |
| **remote** | /rɪˈmoʊt/ | 远程仓库地址 | GitHub 上那个仓库的 URL |
| **diff** | /dɪf/ | 差异，改了哪些地方 | 两个版本之间的不同之处 |
| **.gitignore** | dot-git-ignore | 忽略文件列表 | 告诉 Git "这些文件不要管" |
| **contribution graph** | /ˌkɑːntrɪˈbjuːʃən ɡræf/ | 贡献热力图 | GitHub 个人主页上那些绿格子 |
| **SSH key** | S-S-H key | 加密密钥，用于免密码登录 | 你的电子身份证，GitHub 用它识别你 |
| **markdown (.md)** | /ˈmɑːrkdaʊn/ | 一种简单的文本格式 | 纯文本就能写出带标题、列表、代码块的文档 |

---

## 二、Git 工作原理（用拍照来理解）

```
工作目录                 暂存区                 本地仓库              GitHub（远程仓库）
(你正在改的文件)   ────  (选好的文件)  ────  (所有存档)  ────  (云端的备份)
                 git add            git commit          git push
                                                        ←────
                                                        git pull
```

**日常流程就是四步：**

1. 写代码 / 写笔记 —— 在你的文件夹里改文件
2. `git add .` —— 告诉 Git：这些文件我要存档
3. `git commit -m "今天学了列表推导式"` —— 拍一张快照，写好备注
4. `git push` —— 上传到 GitHub

---

## 三、第一次配置（我们现在就做）

### 第 1 步：打开 GitHub 网站

浏览器打开 https://github.com

- 如果没有账号，点右上角 **Sign up**（注册）
- 用户名用简短好记的英文，比如 `cileap`（你已经有了）
- 注册后会到这个页面：`https://github.com/你的用户名`

### 第 2 步：创建一个新仓库

- 登录后，点右上角的 **+** → **New repository**
- Repository name（仓库名）填：`learning-journey`（学习旅程）
- Description（描述）填：`记录我的编程学习过程`
- 选择 **Public**（公开的，别人能看到，热力图才能全绿）
- **不要**勾选 "Add a README file"（我们手动创建）
- 点 **Create repository**
- 页面会显示类似这样的地址：
  - `https://github.com/cileap/learning-journey.git`

### 第 3 步：配置 SSH 免密码登录

每次 push 都要输密码很烦，SSH key 能让你免密码。在 Git Bash 里运行：

```bash
# 生成密钥（一路回车即可，不用设密码）
ssh-keygen -t ed25519 -C "3656068815@qq.com"

# 把公钥显示出来，复制全部内容
cat ~/.ssh/id_ed25519.pub
```

然后：
1. 打开 https://github.com/settings/keys
2. 点 **New SSH Key**
3. Title 随便填（比如 "我的Windows电脑"）
4. Key 里粘贴刚才复制的内容
5. 点 **Add SSH Key**

验证（在 Git Bash 里）：
```bash
ssh -T git@github.com
# 看到 "Hi cileap!" 字样就成功了
```

---

## 四、初始化你的学习仓库

打开 **Git Bash**（Windows 开始菜单搜 "Git Bash"），一行一行敲：

```bash
# 1. 在桌面创建一个文件夹
mkdir ~/Desktop/learning-journey
cd ~/Desktop/learning-journey

# 2. 初始化 Git 仓库
git init

# 3. 创建第一个文件
echo "# 我的编程学习记录" > README.md
echo "" >> README.md
echo "从 2026 年 8 月 4 日开始，每天记录学习内容。" >> README.md

# 4. 第一次存档
git add README.md
git commit -m "初始化仓库，开始学习之旅"

# 5. 关联远程仓库（把下面 cileap 换成你的 GitHub 用户名）
git remote add origin git@github.com:cileap/learning-journey.git

# 6. 推送到 GitHub
git branch -M main
git push -u origin main
```

回到 GitHub 页面刷新，你就能看到 README.md 了。同时你的个人主页会出现**第一个绿点**。

---

## 五、每日学习记录模板

在 `learning-journey` 文件夹里，每天创建一个文件。格式像这样：

### 文件夹结构（建议）

```
learning-journey/
├── README.md
├── 2026-08/
│   ├── 2026-08-04.md    ← 今天的笔记
│   ├── 2026-08-05.md
│   └── ...
├── python/
│   ├── day01_hello_world.py
│   ├── day02_list_comprehension.py
│   └── ...
├── cpp/
│   ├── day01_pointers.cpp
│   └── ...
└── .gitignore
```

### `2026-08-04.md` 的写法（你今天的笔记）

```markdown
# 2026-08-04 学习记录

## 今天学了什么
- GitHub 基本概念：repo、commit、push、pull
- Git 工作流程：add → commit → push

## 遇到的困难
- 很多英文名词看不懂，需要慢慢熟悉

## 明天计划
- 学习 Python 变量和数据类型
- 做 5 道 LeetCode 简单题

## 代码练习
见 python/day01_xxx.py
```

---

## 六、每天操作流程（重复用的命令）

打开 Git Bash，cd 到你的仓库：

```bash
cd ~/Desktop/learning-journey

# 1. 拉取最新内容（防止你在多台电脑用）
git pull

# 2. 写你的笔记和代码...（用 VS Code 编辑）
# 比如创建了 2026-08-05.md 和 python/xxx.py

# 3. 查看你改了什么
git status

# 4. 暂存所有修改
git add .

# 5. 提交，写清楚今天干了什么
git commit -m "0815: 学了列表推导式，刷了3道LeetCode"

# 6. 推送到 GitHub
git push
```

然后去看 `https://github.com/你的用户名/learning-journey`，热力图会多一个绿点。

---

## 七、常见问题

### Q: `git push` 失败，报 permission denied？
说明 SSH 没配好。按照上面第 3 步重做。

### Q: `git push` 失败，报 rejected？
说明远程仓库有本地没有的内容。先 `git pull` 再 `git push`。

### Q: 改了文件但不想提交了？
`git checkout -- 文件名`  恢复单个文件
`git reset --hard`  恢复所有文件（谨慎！）

### Q: commit 信息写错了怎么办？
如果还没 push：`git commit --amend -m "新的信息"`

### Q: Git Bash 里粘贴快捷键是什么？
按 `Insert` 键，或者 `Shift + Insert`，或者右键粘贴。

---

## 八、GitHub 热力图（Contribution Graph）

这是你的学习激励核心——你的主页上那张绿色格子图。

**规则：**

| 格子颜色 | 含义 |
|----------|------|
| 深绿色 | 当天有多个 commit |
| 浅绿色 | 当天有 1-3 个 commit |
| 空白 | 当天没有 commit |

**怎么让它绿：**

- 每天至少 commit 一次并 push 到 GitHub
- 即使只是写了几行笔记，也 commit
- commit 的邮箱必须和 GitHub 账号的邮箱一致

**坚持 3 个月后，你会看到一排整齐的绿格子，这是最直观的学习证明。**

---

## 九、你现在要做的（按顺序）

1. [ ] 去 github.com 注册账号（如果还没有的话）
2. [ ] 在 GitHub 上创建 `learning-journey` 仓库
3. [ ] 看完上面第 3 步，给我说"第 3 步做好了"，我帮你继续往下做
