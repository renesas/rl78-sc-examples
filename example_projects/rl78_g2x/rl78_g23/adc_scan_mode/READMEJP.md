# RL78/G23 A/Dコンバータ (スキャン・モード)

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G23のA/Dコンバータ（スキャン・モード）を用いたアナログ電圧の変換方法について説明します。複数の入力チャネル（ANI2～ANI5）のアナログ信号をデジタル値へ変換し、その結果をデータ変換して内蔵RAMへ格納します。A/Dコンバータの設定方法や変換完了処理についても解説しています。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | V8.10.00 |
| e2 studio | V2023-10 (23.10.0) |
| CC-RL | V1.12.01 |
| IAR Embedded Workbench | V5.10.1 |
| IAR Compiler | V5.10.1 |
| Smart Configurator | V1.8.0 |
| BSP | V1.00 |

## ハードウェア構成
- RL78/G23 Fast Prototyping Board (RTK7RLG230CLG000BJ)
- 測定対象アナログ入力信号

## 適用可能デバイス
- RL78/G23

## APNリンク
[RL78/G23 A/Dコンバータ (スキャン・モード)](https://www.renesas.com/ja/document/apn/rl78g23-ad-converter-scan-mode)
