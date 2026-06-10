# RL78/G24 タイマRG2 位相計数モード

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G24のタイマRG2の位相計数モードを使用し、TRGCLKAおよびTRGCLKB端子からの外部信号の位相差を検出する方法を説明します。位相差に応じてTRGカウンタをアップ／ダウンカウントします。また、TRGIDZ端子の有効エッジ検出によりカウンタクリア割り込みを発生させ、ポートをトグルします。割り込み処理と位相検出の動作を具体的に示します。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | V8.10.00 |
| e2 studio | 2023-07 (23.7.0) |
| CC-RL | V1.12.01 |
| IAR Embedded Workbench | V4.21.1 |
| IAR Compiler | V4.21.1 |
| Smart Configurator | V.1.7.0 |
| BSP | V.1.60 |

## ハードウェア構成
- RL78/G24 Fast Prototyping Board (RTK7RLG240C00000BJ)

## 適用可能デバイス
- RL78/G24

## APNリンク
[RL78/G24 タイマRG2 位相計数モード](https://www.renesas.com/ja/document/apn/rl78g24-timer-rg2-phase-counting-mode-rev100)
