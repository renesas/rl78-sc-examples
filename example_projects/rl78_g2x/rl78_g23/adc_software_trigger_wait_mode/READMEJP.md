# RL78/G23 A/Dコンバータ (ソフトウエア・トリガ・ウエイト・モード)

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G23のA/Dコンバータのソフトウエア・トリガ・ウエイト・モードの使用方法を説明します。ANI2端子に入力されたアナログ電圧をA/D変換し、デジタル値として取得します。変換完了はHALTモードで待機し、割り込みで復帰します。変換結果は内蔵RAMに格納されます。初期設定やトリガ制御、割り込み処理についても解説しています。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | E8.09.00 |
| e2 studio | V2023-04 (23.4.0) |
| CC-RL | V1.12.00 |
| IAR Embedded Workbench | V4.21.2 |
| IAR Compiler | V4.21.2.2420 |
| Smart Configurator | V1.6.0 |
| BSP | V1.60 |

## ハードウェア構成
- RL78/G23-64p Fast Prototyping Board (RTK7RLG230CLG000BJ)
- 測定対象アナログ入力信号

## 適用可能デバイス
- RL78/G23

## APNリンク
[RL78/G23 A/Dコンバータ (ソフトウエア・トリガ・ウエイト・モード)](https://www.renesas.com/ja/document/apn/rl78g23-ad-converter-software-trigger-wait-mode)
