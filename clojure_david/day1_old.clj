; Part 1
(doseq [
    num1 data
    num2 data
    :when (= 2020 (+ num1 num2) )
    :let [res (* num1 num2)]
  
  ]
  (def result1 res)
)
(println "Part1 result:" result1)

; Part 2
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