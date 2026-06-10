# RL78/G22 A/Dコンバータ (ソフトウエア・トリガ、連続変換モード)

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G22のA/Dコンバータをソフトウエア・トリガおよび連続変換モードで使用する方法を説明します。単一チャネルのアナログ入力電圧をデジタル値に変換する例を示しています。変換結果は加工後、内蔵RAMに格納されます。サンプルプログラムではHALTモードで変換完了を待ち、割り込みにより結果処理を行います。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | E8.10.00 |
| e2 studio | V2023-01 (23.1.0) |
| CC-RL | V1.12.01 |
| IAR Embedded Workbench | V5.10.1 |
| IAR Compiler | V5.10.1.2673 |
| Smart Configurator | V1.5.0 |
| BSP | V1.40 |

## ハードウェア構成
- RL78/G22 Fast Prototyping Board
- 外部アナログ入力信号

## 適用可能デバイス
- RL78/G22

## APNリンク
[RL78/G22 A/Dコンバータ (ソフトウエア・トリガ、連続変換モード)](https://www.renesas.com/ja/document/apn/rl78g22-ad-converter-software-trigger-and-sequential-conversion-modes-rev102)
