object DataModule1: TDataModule1
  OldCreateOrder = False
  Height = 444
  Width = 510
  object ADOConnection1: TADOConnection
    ConnectionString = 
      'Provider=MSDASQL.1;Persist Security Info=False;Data Source=hona_' +
      'malumotlari'
    LoginPrompt = False
    Provider = 'MSDASQL.1'
    Left = 24
    Top = 208
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    SQL.Strings = (
      'select * from Hona')
    Left = 128
    Top = 152
  end
  object DataSource1: TDataSource
    DataSet = ADOQuery1
    Left = 240
    Top = 160
  end
end
