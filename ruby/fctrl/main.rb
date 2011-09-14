def right_zeros(number)
  number = number.to_i
  number_of_fives(number)
end

def number_of_fives(number)
  numeral = 0
  while number > 0
    number = number / 5
    numeral += number
  end
  numeral
end

tests = gets.chomp.to_i
tests.times do
  puts right_zeros(gets.chomp)
end