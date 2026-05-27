# RL78 Examples based on Smart Configurator 
English page is [here](./README.md).
 <br>
 
## 概要
このリポジトリでは、Smart Configurator で作成された Renesas RL78 MCU ファミリ向けサンプルコードを提供します。 <br>
 <br>

## リポジトリ内容
### Example projects
Example Project（EP）は、シンプルで独立した例を通じて、各周辺機能の動作を理解することに重点を置いたプロジェクトです。  <br>
基本的な周辺機能を対象としたサンプルコードを提供します。

**例：** Interval Timer, UART, AD Converterなど
 <br>
 <br>
 
### Application projects (Coming soon)
Application Projects (AP) は、アプリケーションノートおよび実ユースケースに基づいた実装例を示すプロジェクトです。<br>
実際のシステムへの適用方法を示すようなサンプルコードを提供します。

**例：** Flash Programmer, Capacitive Touch, Safety Functionなど
 <br>
 <br>
 
## このリポジトリの使用方法
### サンプルコードを探す
プロジェクトの探し方の例を以下に示します。<br>
 <br>
#### RL78/G23 でタイマを評価したい場合：
1. [example_project](./example_project)を選択します。
2. デバイスシリーズのディレクトリ (`rl78_g2x`) を選択します。
3. 対象デバイスのディレクトリ（`rl78_g23`）を選択します。
4. タイマ関連のサンプルプロジェクトを選択します。<br>
   複数のタイマサンプルが用意されているため、用途に最も適したものを選択してください。

### クイックスタート
1. 以下のいずれかの方法でプロジェクトを取得してください。

- **zip ファイルをダウンロードする場合**  
GitHub Releases から、使用したいデバイスまたはカテゴリの最新リリースノートを見つけてください。
Assets セクションから ZIP ファイルをダウンロードし、必要なプロジェクトを取得してください。
<img width="720" height="210" alt="image" src="https://github.com/user-attachments/assets/d2503727-a5cc-4f85-a4ee-79a0e60b879c" />

- **リポジトリをクローンする場合**  
  Git を使用して本リポジトリを clone します。<br>
  e2studio(IDE)は、Git機能を備えており、e2studio上でcloneを行うこともできます。
  <img width="511" height="543" alt="image" src="https://github.com/user-attachments/assets/65b45fa6-403d-4d6f-9b80-eb9d889fec83" />


2. 必要なソフトウェア、ハードウェア構成をREADMEファイルを見て用意します。
3. IDEでインポートして動作を開始します。<br>
   以下のいずれかのIDEを使用できます。
   - [CS+](https://www.renesas.com/en/software-tool/cs)
   - [e2studio](https://www.renesas.com/en/software-tool/e2-studio)
   - [IAREW](https://www.iar.com/embedded-development-tools)
 
## 対象デバイス
- RL78/G1x (Comming soon)
- RL78/G2x
- RL78/Lxx (Comming soon)
- RL78/I1x (Comming soon)
- RL78/H1D (Comming soon)

 
## リンク
- RL78 Auto：Coming soon
- RL78 Software：Coming soon
- RL78 製品ページ：https://www.renesas.com
- RL78 Arduino：https://github.com/renesas/Arduino/wiki
