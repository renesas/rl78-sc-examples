# RL78/G24 A/Dコンバータ（アドバンスド・モードON）

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G24のA/Dコンバータ（アドバンスド・モードON）の機能と動作について、2つの使用例を用いて説明しています。複数チャネル変換、トリガ割り当て、割り込み制御などの特徴を解説しています。ハードウェア／ソフトウェア混在トリガ動作および同時サンプリングの実装例を示しています。設定方法とサンプルコードにより、実機評価までを支援します。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | V8.12.00 |
| e2 studio | 2024-10 (24.10.0) |
| CC-RL | V1.14.00 |
| IAR Embedded Workbench | V5.10.3 |
| IAR Compiler | V5.10.3 |
| Smart Configurator | V.1.11.0 |
| BSP | V.1.70 |

## ハードウェア構成
- RL78/G24 Fast Prototyping Board (RTK7RLG240C00000BJ)
- 外部アナログ信号源

## 適用可能デバイス
- RL78/G24

## APNリンク
[RL78/G24 A/Dコンバータ（アドバンスド・モードON）](https://www.renesas.com/ja/document/apn/rl78g24-ad-converter-advanced-mode-enabled-rev100)
