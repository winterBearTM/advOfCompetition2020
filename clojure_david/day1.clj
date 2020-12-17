(defn part1 [numbers]                               ; defn - shorthand for function definition, part1 is name, [] contains arguments (arbitrary amount of args with &)
  (for                                              ; loops are not the most functional, should use recursion, but hey
    [
      num1 numbers
      num2 numbers
      :let [result (* num1 num2 )]
      :when (= 2020 (+ num1 num2))
    ]
    result
  )                                                 
)

(defn part2 [numbers]                               ; defn - shorthand for function definition, part1 is name, [] contains arguments (arbitrary amount of args with &)
  (for                                              ; loops are not the most functional, should use recursion, but hey
    [
      num1 numbers                                  ; here I tell it how many levels this loop has (this is a two level for loop)
      num2 numbers                                  ; numbers - where to take values from, num1 and num2 - values
      num3 numbers
      :let [result (* num1 num2 num3)]                  ; let - locally visible variable (only in this loop)
      :when (= 2020 (+ num1 num2 num3))                  ; when triggers let in for loop when condition satisfied
    ]
    result                                          ; no explicit return statement, last expression is the value returned
  )                                                 
)

; I would like to make just one recursive function for both parts, but must learn how to first.

(def lines (clojure.string/split-lines (slurp "data/day1.txt")))      ; Split text into vector of lines
(println "Part1 result:" (part1 (map #(Integer/parseInt %) lines)))   ; map is a nice functional feature, applies function (1st argument) to all other arguments (in this case list of strings that it converts to ints)
(println "Part2 result:" (part2 (map #(Integer/parseInt %) lines)))