require 'rubygems'
require 'sinatra'
require 'ruby_spark'

enable :sessions

get '/' do
  @core = RubySpark::Core.new(ENV['CORE_ID'], ENV['ACCESS_TOKEN'])
  @cook_status = if @core.variable('on') == 0
                    'off'
                  else
                    'on'
                  end

  erb :index
end

post '/cook' do
  @core = RubySpark::Core.new(ENV['CORE_ID'], ENV['ACCESS_TOKEN'])
  @status = params[:status]
  @core.function('toggleOn', @status)

  redirect to('/')
end
