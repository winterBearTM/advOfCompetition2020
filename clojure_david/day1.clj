(def data
  [
1728
1954
1850
1825
1732
1536
1759
1877
1400
1579
1708
1047
1810
558
1132
1608
1857
1756
1834
1743
1888
1660
1642
1726
541
1519
1407
1875
1618
1331
1878
1626
1200
1346
1830
1403
1557
1890
1543
823
1435
1903
1377
1931
1885
1422
1411
1563
1818
1643
2004
1364
1446
1071
1699
1140
1617
1974
1758
1537
1980
1709
1812
1178
1822
1648
1517
1477
1935
1848
1534
1734
1484
1985
1485
1963
1329
1809
1380
1552
1895
215
1844
1138
1194
1938
1774
1823
684
1948
1941
1062
1550
1602
1920
1391
1666
1327
1791
1721
1928
1805
1574
1658
1467
1852
1924
1679
2008
1989
1719
1884
1776
1806
1750
1897
1781
1667
1544
1100
1838
1839
1744
1715
1481
1480
1548
1707
1362
1681
1616
1956
1639
1911
1655
1685
1670
1789
1571
1661
1647
1379
1522
1965
1482
1158
1970
1945
1384
1535
1383
1613
1511
1896
1784
1513
841
1619
1645
1125
1932
1873
639
1657
1554
1979
1516
1995
1899
1347
1175
1918
1872
1559
1094
1423
1883
1846
1394
1488
1343
1905
1914
1578
1943
1388
1286
966
1342
1528
1702
1452
1936
2005
1188
1683
1133
447
1072
1893
  ]
)

(def data_small 
	[
		1728
1954
1850
1825
1732
1536
1759
1877
1400
1579
1708
1047
1810
558
1132
1608
1857
1756
1834
1743
1888
1660
1642
1726
541
	]
)

(def data_medium 
	[
		1728
1954
1850
1825
1732
1536
1759
1877
1400
1579
1708
1047
1810
558
1132
1608
1857
1756
1834
1743
1888
1660
1642
1726
541
1519
1407
1875
1618
1331
1878
1626
1200
1346
1830
1403
1557
1890
1543
823
1435
1903
1377
1931
1885
1422
1411
1563
1818
1643
2004
1364
1446
1071
1699
1140
1617
1974
1758
1537
1980
1709
1812
1178
1822
1648
1517
1477
1935
1848
1534
1734
1484
1985
1485
1963
1329
1809
1380
1552
1895
215
1844
1138
1194
1938
1774
1823
684
	]
)

(println "Hello World")

; Part 1
(def result1 nil)
(doseq [
    num1 data
    num2 data
  :let [res (* num1 num2)]
  :when (= 2020 (+ num1 num2) )
  ]
  (def result1 res)
)
(println "Part1 result:" result1)

; Part 2
(def result2 nil)
(doseq [
    num1 data
    num2 data
    num3 data
  :let [res (* num1 num2 num3)]
  :when (= 2020 (+ num1 num2 num3) )
  ]
  (def result2 res)
)

(println "Part2 result:" result2)
