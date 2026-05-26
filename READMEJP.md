# RL78 Examples based on Smart Configurator 
English page is [here](./README.md).
 <br>
 
## 概要
このリポジトリでは、Smart Configurator で作成された Renesas RL78 MCU ファミリ向けサンプルコードを提供します。
 <br>
 <br>

## リポジトリ内容
### Example projects
Example Project（EP）は、シンプルで独立した例を通じて、各周辺機能の動作を理解することに重点を置いたプロジェクトです。  
基本的な周辺機能を対象としたサンプルコードを提供します。

**例：** Interval Timer, UART, AD Converterなど
 <br>
 <br>
 
### Application projects
アプリケーションノートおよび実ユースケースに基づいた実装例を示すプロジェクトで、実際のシステムへの適用方法を示すサンプルコードを提供します。

**例：** Flash Programmer, Capacitive Touch, Safety Functionなど
 <br>
 <br>
 
## このリポジトリの使用方法
### サンプルコードを探す
プロジェクトの探し方の例を以下に示します。詳細については、[Wiki](https://github.com/Mizuki-NAKAMURA-REL/aaaaa/wiki/Home-JP) を参照してください。<br>
 <br>
#### RL78/G13 でタイマを評価したい場合：
1. [example_project](./example_project)を選択します。
2. デバイスシリーズのディレクトリ (`rl78_g1x`) を選択します。
3. 対象デバイスのディレクトリ（`rl78_g13`）を選択します。
4. タイマ関連のサンプルプロジェクトを選択します。<br>
   複数のタイマサンプルが用意されているため、用途に最も適したものを選択してください。

#### シリアルプログラミングのプロジェクトを参照したい場合：
1. [application_project](./application_project)を選択します。
2. カテゴリディレクトリ(`programmer`)を選択します。
3. 使用環境やユースケースに応じたプロジェクトのディレクトリを選択します。<br>
   各ディレクトリ内の README を参照し、実装したいアプリケーションに適したプロジェクトを選択してください。

### クイックスタート
1. 以下のいずれかの方法でプロジェクトを取得してください。

- **zip ファイルをダウンロードする場合**  
   使用したいプロジェクトのzipファイルをGitHub上で開き、Download raw fileボタン(画像赤枠)からダウンロードしてください。<br>
   <img width="936" height="337" alt="image" src="https://github.com/user-attachments/assets/9a7b986f-c2b3-43e4-933a-8b15bf8165ed" />

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
- RL78/G1x
- RL78/G2x
- RL78/Lxx
- RL78/I1x
- RL78/H1D

## ライセンス
Smart Configurator V1.16.00 以降で生成されるコードは全て[BSD 3-Clause](./LICENSE.md)が適用されます。<br>
 <br>
 
## リンク
- RL78 Auto：
- RL78 Software：
- RL78 製品ページ：https://www.renesas.com
- RL78 Arduino：https://github.com/renesas/Arduino/wiki
 
## Contributions
詳細は [CONTRIBUTING](CONTRIBUTING.md) を参照してください。
