def to_rpn(expression)
  rpn = ""
  operators = []
  expression.each_char do |char|
    if char == "("
      # nope
    elsif char =~ /[*^+-\/]/
      operators << char
    elsif char == ")"
      rpn << operators.pop
    else
      rpn << char
    end
  end
  
  rpn
end

tests = gets.chomp.to_i
tests.times do
  puts to_rpn(gets.chomp)
end