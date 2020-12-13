; Intro to Clojure:
; LISP dialect that runs in JVM
; there is also ClojureScript that transpiles into JavaScript
; Mostly functional, but because JVM, not entirely (it tries so hard though)
; because JVM, can also use regular Java modules, functions, libraries...
; expressions contained in (), no statements
; U R not supposed to change variable values (because functional - no side effects and no state)
; oh and ; is an inline comment if you haven't noticed
; dont know how to multiline comment yet unfortunately
; but I have learned to read files!
; calling a function goes like this: (functionName arguments...) including for stuff like adding as you see, no operators! (concise syntax and shit)

(defn part1 [numbers]                               ; defn - shorthand for function definition, part1 is name, [] contains arguments (arbitrary amount of args with &)
  (for                                              ; loops are not the most functional, should use recursion, but hey
    [                                               ; I'm using doseq instead of for because for prints some trash in console, it's the same shit otherwise
      num1 numbers                                  ; here I tell it how many levels this loop has (this is a two level for loop)
      num2 numbers                                  ; numbers - where to take values from, num1 and num2 - values
      :let [result (* num1 num2 )]                  ; let - locally visible variable (only in this loop)
      :when (= 2020 (+ num1 num2))                  ; when triggers let in for loop when condition satisfied
    ]
    result                                          ; no explicit return statement, last expression is the value returned
  )                                                 
)

(def filetext (slurp "day1.txt"))                                     ; Read file as string into "filetext" variable
(def lines (clojure.string/split-lines filetext))                     ; Split lines into vector of lines
(println "Part1 result:" (part1 (map #(Integer/parseInt %) lines)))   ; map is a nice functional feature, applies function (1st argument) to all other arguments (in this case list of strings that it converts to ints)