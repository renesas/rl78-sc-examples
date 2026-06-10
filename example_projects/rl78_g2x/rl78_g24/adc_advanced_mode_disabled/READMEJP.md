# RL78/G24 A/Dコンバータ（アドバンスド・モードOFF）

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G24のA/Dコンバータ（アドバンスド・モードOFF）の動作について説明します。ソフトウェア・トリガによる内部基準電圧の変換と、RTC割り込みを用いたハードウェア・トリガのスキャン動作の2つの使用例を示します。設定手順や動作フロー、サンプルコード構成について解説し、変換結果は内蔵RAMに格納されます。

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
- アナログ入力信号源

## 適用可能デバイス
- RL78/G24

## APNリンク
[RL78/G24 A/Dコンバータ（アドバンスド・モードOFF）](https://www.renesas.com/ja/document/apn/rl78g24-ad-converter-advanced-mode-disabled-rev100)
