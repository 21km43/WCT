# WCT
Slotted ALOHAとTDMAのシミュレーションプログラム

Visual Studio 2022で開発（OS依存のライブラリは使用していない）

# Usgae
そのまま実行してもOK。どのようなシミュレーション方法で実行するか、局数はいくつか、必要であれば遅延時の再送率を入力すると出力される。
スロットの数、各局の送信率の範囲を変えたい場合はソースコードを改変して再度コンパイルすること。

実行時引数でこれらのパラメータを指定することも可能。csvとして出力したい場合は、次のようにすれば良い（実行ファイル名がWCTでWindowsで実行する場合）
```
WCT.exe (Simulation mode) (Number of stations) (Delay lambda) > out.csv
```
省略すると、その部分のみ入力を求められる

# License
[MIT License](/LICENSE.txt)
